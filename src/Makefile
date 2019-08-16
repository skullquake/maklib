CXX=g++
AR=ar
SOURCEDIR=./src/libcpputils
SOURCES:=$(shell find $(SOURCEDIR) -name '*.cpp')
DYBUILDDIR=bin/shared
SBUILDDIR=bin/static
DYLIBOBJS:=$(addprefix $(DYBUILDDIR)/,$(SOURCES:%.cpp=%.o))
SLIBOBJS:=$(addprefix $(SBUILDDIR)/,$(SOURCES:%.cpp=%.o))
SRCDRV=./src/a.cpp
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
CXXFLAGS=\
	-Wall\
	-Werror\
	-I./include/libcpputils
LDFLAGS=
DYBIN=./bin/a_shared
SBIN=./bin/a_static
DYLIB=./lib/libcpputils.dll
SLIB=./lib/libcpputils_static.a
all:\
	$(SBIN)\
	$(DYBIN)
$(DYBIN):$(DYLIB) $(SRCDRV)
	@mkdir -p $(@D)
	@$(CXX)\
		$(CXXFLAGS)\
		-L./lib\
		$(SRCDRV)\
		$(LDFLAGS)\
		-lcpputils\
		-o $(DYBIN)
$(SBIN):$(SLIB) $(SRCDRV)
	@mkdir -p $(@D)
	@$(CXX)\
		$(CXXFLAGS)\
		-L./lib\
		$(SRCDRV)\
		$(LDFLAGS)\
		$(SLIB)\
		-o $(SBIN)
$(DYLIB): $(DYLIBOBJS)
	@mkdir -p $(@D)
	@printf "generating $@...\n"
	@$(CXX)\
		$(CXXFLAGS)\
		-shared\
		$(DYLIBOBJS)\
		-o $(DYLIB)
$(SLIB): $(SLIBOBJS)
	@mkdir -p $(@D)
	@printf "generating $@...\n"
	@$(AR)\
		rcs\
		$(SLIB)\
		$(SLIBOBJS)
$(DYBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CXX)\
		$(CXXFLAGS)\
		$(LDFLAGS)\
		-fpic\
		-I$(HEADERDIR)\
		-I$(dir $<)\
		-c $<\
		-o $@
$(SBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CXX)\
		$(CXXFLAGS)\
		$(LDFLAGS)\
		-I$(HEADERDIR)\
		-I$(dir $<)\
		-c $<\
		-o $@

.phony:\
	runshared\
	runstatic\
	clean\
	install\
	distclean
runshared:
	@export PATH=./lib:$$PATH:$$PATH;$(DYBIN) 
runstatic:
	@$(SBIN) 
run:
	@$(SBIN) 
	@export PATH=./lib:$$PATH:$$PATH;$(DYBIN) 
install: $(DYLIB) $(SLIB)
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $(DYLIB) $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $(SLIB) $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/include/
	install -d $(DESTDIR)$(PREFIX)/lib/pkg-config
	install -m 644 ./src/pkg-config/*.pc $(DESTDIR)$(PREFIX)/lib/pkgconfig
	cp -r ./include/* $(DESTDIR)$(PREFIX)/include/
clean:
	@rm -r ./bin ./lib
distclean:
	rm\
		-r\
		$(DYBUILDDIR)\
		$(SBUILDDIR)
