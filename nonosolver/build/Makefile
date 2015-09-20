##
## Makefile for nonosolver
## Made by nicuveo <crucuny@gmail.com>
##

include Makefile.rules



# VARIABLES

LOGIN = nicuveo
PROJ  = nonosolver

EXE   = ../bin/$(PROJ)
LIBA  = ../bin/lib$(PROJ).a

OBJS  = $(notdir $(CFIL:.cc=.o))
DEPS  = $(notdir $(CFIL:.cc=.d))



# MAIN

all: $(TARGET)

clean: do_clean

distclean: do_distclean



# CLEAN

do_clean:
	rm -f $(OBJS)

do_distclean: do_clean
	rm -f $(EXE) $(LIBA) $(LIBSO) $(DYLIB) $(DEPS)
	rm -f Makefile.rules Makefile.deps tmp



# COMPIL

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXE)

$(LIBA): $(OBJS)
	ar -scr $(LIBA) $(OBJS)

$(LIBSO): $(OBJS)
	$(CC) -shared $(OBJS) $(LDFLAGS) -o $(LIBSO)

$(DYLIB): $(OBJS)
	$(CC) -dynamiclib $(OBJS) $(LDFLAGS) -o $@

$(OBJS):
	$(CC) $(CFLAGS) -c $< -o $@



# DEPS

Makefile.deps:
	rm -f $@
	@echo "-- Regenerating basic dependencies"
	@for f in $(CFIL) ; do \
	echo "`basename $$f`: \\" | sed 's/\(.*\)\.cc/\1.d/' >> $@; \
	echo "$$f" >> $@ ; done
	@echo "-include $(DEPS)" >> Makefile.deps

$(DEPS):
	@echo "$(CC) -MM $< > $@"
	@$(CC) $(CFLAGS) -MM $< -MT "$(@:.d=.o) $@" > tmp
	@mv tmp $@



include Makefile.deps
