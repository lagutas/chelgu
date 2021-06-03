FROM ubuntu:18.04

RUN apt-get update \
    && apt-get install --no-install-recommends -yq openssh-server netcat \
    && rm -rf /var/lib/apt/lists/* \
    && adduser --disabled-password --gecos '' user \
    && echo user:password | chpasswd \
    && mkdir /var/run/sshd
    
EXPOSE 22 80 7566

CMD ["/usr/sbin/sshd", "-D"]
