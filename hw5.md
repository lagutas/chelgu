1 Как отобразить 4 последних выполненных команды?

	history 4

2 Перевести задание в фоновый режим в bash можно командой

	bg pid

3 Какая комбинация клавиш переключит вас на 4-ю виртуальную консоль?

	ctrl+alt+f4

4 Какая переменная среды содержит путь к домашнему каталогу?

	HOME

5 Установить в bash переменную MYVAR в качестве системной можно командой?

	export MYVAR

6 Какие комбинации клавиш позволят выделить несколько файлов в Midnight Commander?

	ctrl+t

Сценарий 1:

	Вывод: $VAR

Сценарий 2:

	Вывод: /etc

Сценарий 3:

	Вывод: 2

Задача 1:

	#!/bin/bash
	a=$1
	b=$2
	c=$3
	d=$4
	result=""
	for(( i=0; i<a; i++ ))
	do
	   result+="$d"
	   for(( j=1; j<b-1; j++ ))
	   do
	      if ((c == 1 )) || (( i == 0 )) || (( i == a-1 )); then
	         result+="$d"
	      else
	         result+=" "
	      fi
	   done
	   result+="$d\n"
	done
	printf "$result"

Задача 2:

	Запуск: tmux commands options

	Создать новое окно: ctrl+b c

	Разделить панель по вертикали: ctrl+b %

	Разделить панель по горизонтали: ctrl+b " 

	Поддержка мыши: добавить в файл(если нет, то создать) ~/.tmux.conf следующие строки
	set-option -g -q mouse on
	bind-key -T root WheelUpPane if-shell -F -t = "#{alternate_on}" "send-keys -M" "select-pane -t =; copy-mode -e; send-keys -M"
	bind-key -T root WheelDownPane if-shell -F -t = "#{alternate_on}" "send-keys -M" "select-pane -t =; send-keys -M"

	Изменить размер панели: ctrl+b ctrl+arrow

	Прокрутка: ctrl+b [ arrow

	Закрыть панель: ctrl+b x

	detach: Отключение от сессии