INCLUDE = -I include
CFLAGS = -fpic -Wall -Werror
LFLAGS = -ldl
OBJS = vip_reflash.o  gmsl_uart.o  maxim.o  vip_set_termios.o  us_gpio.o ipcl_util.o
VPATH = ./src

#DESTDIR = ../../output
DEVICE = vip
PLUGIN = lib${DEVICE}_plugin.so


${PLUGIN} : ${OBJS}
		@echo "Building $@"
			${CC} -shared -o $@ $^ ${INCLUDE} ${CFLAGS}

%.o : %.c
		${CC} -c $< -o $@ ${INCLUDE} ${CFLAGS} ${LFLAGS}

.PHONY = clean dist-clean

clean :
		-rm -rf *.o *.so ${DESTDIR}/${PLUGIN}

dist-clean:
		-rm -rf *~
