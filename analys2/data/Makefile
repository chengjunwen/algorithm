LIBPATH = -L"/opt/intel/composer_xe_2013.5.192/mkl/lib/intel64" "/opt/intel/composer_xe_2013.5.192/mkl/lib/intel64"/libmkl_intel_lp64.a -Wl,--start-group "/opt/intel/composer_xe_2013.5.192/mkl/lib/intel64"/libmkl_intel_thread.a "/opt/intel/composer_xe_2013.5.192/mkl/lib/intel64"/libmkl_core.a -Wl,--end-group -L"/opt/intel/composer_xe_2013.5.192/mkl/../compiler/lib/intel64"

LIBS = -liomp5 -lpthread -ldl -lm -pg
INCLUDE = -I../include -I/opt/intel/composer_xe_2013.5.192/mkl/include
CPPFLAGS = -g -std=c++0x -fopenmp -Wall ${INCLUDE}

#OBJ_PATH =./obj/
#TARGET_PATH=./bin

#diff_job = ./assign1/diffWeight.cpp
#ratio_job =./assign1/ratioWeight.cpp
#prim_MST =./assign1/primMST.cpp
#cluster =./assign2/k_cluster.cpp
#big_cluster =./assign2/big_cluster.cpp
#knapsack =./assign3/knapsack.cpp
#bellman =./assign4/bellman.cpp
MODELS = knapsack bellman
OBJECTS = knapsack.o bellman.o
OBJECTS := $(patsubst %, src/%, $(OBJECTS))
$(MODELS) : % : src/%.o $(OBJECTS)
	g++ $^ ${LIBPATH} ${LIBS} -o $@

#$(OBJECTS) : %.o : %.cpp
#	g++ $(CPPFLAGS) -o $@ $<

.cpp.o:
	g++ $(CPPFLAGS) -o $@ $<

.c.o:
	g++ $(CPPFLAGS) -o $@ $<
test:
	echo $(OBJECTS)
#diffJob:${diff_job}
#	g++ ${CPPFLAGS} ${diff_job} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@
#ratioJob:${ratio_job}
#	g++ ${CPPFLAGS} ${ratio_job} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@
#prim:${prim_MST}
#	g++ ${CPPFLAGS} ${prim_MST} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@
#clustering:${cluster}
#	g++ ${CPPFLAGS} ${cluster} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@
#big_clustering:${big_cluster}
#	g++ ${CPPFLAGS} ${big_cluster} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@

#knap:${knapsack}
#	g++ ${CPPFLAGS} ${knapsack} ${LIBPATH} ${LIBS} -o ${TARGET_PATH}$@

clean:   
#	rm -rf ${TARGET_PATH}diffJob ${TARGET_PATH}ratioJob ${TARGET_PATH}prim_MST ${TARGET_PATH}clustering ${TARGET_PATH}big_clustering ${TARGET_PATH}knap
	rm -rf $(MODELS) $(OBJECTS) src/*.o
