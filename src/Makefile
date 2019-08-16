CXX=g++
BUILDDIR=bin
SOURCEDIR=./src
SOURCES:=$(shell find $(SOURCEDIR) -name '*.cpp')

LIBFOLDERS=$(shell ls ./lib)
LIBSL=$(foreach D,$(LIBFOLDERS),-L./lib/$D/lib/)
LIBSLNS=$(foreach D,$(LIBFOLDERS),-l$D_static)
LIBSRP=$(foreach D,$(LIBFOLDERS),-Wl,-rpath=./lib/$D/lib)

LIBSLND=$(foreach D,$(LIBFOLDERS),-l$D)
LIBSCF=$(foreach D,$(LIBFOLDERS),-I./lib/$D/include/)
LIBSS=$(foreach D,$(LIBFOLDERS),./lib/$D/lib/lib$D.a)
LIBSD=$(foreach D,$(LIBFOLDERS),./lib/$D/lib/lib$D.so)


OBJECTS=$(addprefix $(BUILDDIR)/,$(SOURCES:%.cpp=%.o))
CXXFLAGS=\
	-I./include\
	$(LIBSCF)\
	$(LIBSL)
LDFLAGSS=\
       $(LIBSLNS)
LDFLAGSD=\
       $(LIBSLND)
BINS=./bin/a_static
BIND=./bin/a_shared

all: $(LIBSS) $(LIBSD) $(BINS) $(BIND)

$(LIBSS):
	make -C $(@D)/..
$(LIBSD):
	make -C $(@D)/..

$(BINS): $(OBJECTS) $(LIBSS) 
	@mkdir -p $(@D)
	@printf "generating $@...\n"
	$(CXX)\
		$(CXXFLAGS)\
		$(OBJECTS)\
		$(LDFLAGSS)\
		-o $(BINS)
$(BIND): $(OBJECTS) $(LIBSD) 
	@mkdir -p $(@D)
	@printf "generating $@...\n"
	$(CXX)\
		$(CXXFLAGS)\
		$(OBJECTS)\
		$(LIBSRP)\
		$(LDFLAGSD)\
		-o $(BIND)

$(BUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(CXXFLAGS)\
		-I$(HEADERDIR)\
		-I$(dir $<)\
		-c $<\
		$(LDFLAGS)\
		-o $@
.phony:\
	runs\
	rund\
	run\
	clean
runs:
	$(BINS)
rund:
	$(BIND)
run:
	$(BINS)
	$(BIND)
test:
	@echo $(LIBSD)
	@echo $(LIBSS)
	@echo $(LIBSLN)
	@echo $(LIBSL)
	@echo $(LIBSRP)
clean:
	$(foreach D,$(LIBFOLDERS),make -C ./lib/$D clean;)
	rm -r ./bin/*
