# Makefile for PX kernel


CC	=	gcc
LD	=	ld
DD	=	dd

#LD_OPT	=	-s -T ld_script
LD_OPT	=	-s -T ld_script_2
INCLUDE	=	./include
CC_FLAGS=	-Wall -nostdinc -fomit-frame-pointer -O2 -Wstrict-prototypes
BOOT	=	./arch/i386/boot/
KERNEL	=	./kernel/
LIB	=	./lib/


emu:	all bochs
all:	px_32


px_32:

	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(BOOT)init_32.o $(BOOT)init_32.c
	@echo

	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(KERNEL)px_32.o $(KERNEL)px_32.c
	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(KERNEL)debug.o $(KERNEL)debug.c
	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(KERNEL)io.o $(KERNEL)io.c
	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(KERNEL)kb.o $(KERNEL)kb.c
	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(KERNEL)video.o $(KERNEL)video.c
	@echo

	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(LIB)utils.o $(LIB)utils.c
	$(CC) -c $(CC_FLAGS) -I$(INCLUDE) -o $(LIB)string.o $(LIB)string.c
	@echo



	$(LD) $(LD_OPT) -o px.img \
		$(BOOT)init_32.o \
		$(KERNEL)*.o \
		$(LIB)*.o


	@echo
	@echo "Wykonano obraz jadra: px.img"


install:

	$(DD) if=px.img of=/dev/fd0 bs=512 count=20 conv=sync


bochs:
	mount fd1 && cp px.img fd1/ && umount fd1 && bochs -q


clean:
	rm -f px.img
	rm -f *.s $(BOOT)/*.s $(KERNEL)/*.s $(LIB)/*.s
	rm -f *.o $(BOOT)/*.o $(KERNEL)/*.o $(LIB)/*.o
	rm -f *.bin $(BOOT)/*.bin $(KERNEL)/*.bin $(LIB)/*.bin
	rm -f *.block $(BOOT)/*.block $(KERNEL)/*.block $(LIB)/*.block
	rm -f *~ $(BOOT)/*~ $(KERNEL)/*~ $(LIB)/*~


help:
	@echo "Targets:"
	@echo
	@echo "emu"
	@echo "all"
	@echo "px_32    px.img"
	@echo
	@echo "install      instaluje px.img na /dev/fd0"
	@echo "bochs"
	@echo "clean"
	@echo "help"


# EOF
