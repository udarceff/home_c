APPNAME = main
FILENAME = data_list.txt

SRCS += main.c
SRCS += gentemplist.c

all:
	gcc $(SRCS) -o $(APPNAME)

clean: 
	rm -f $(FILENAME)

debug:
	gcc $(SRCS) -o $(APPNAME) -DDEBUG
