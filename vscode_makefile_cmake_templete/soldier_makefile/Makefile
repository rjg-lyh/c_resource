cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(cpp_srcs:.cpp=.cpp.o)
cpp_objs := $(cpp_objs:src/%=objs/%)
cpp_mks := $(cpp_objs:.cpp.o=.cpp.mk)

NO_COLOR=\033[0m
GREEN_COLOR=\033[32;01m
RED_COLOR=\033[31;01m

include_paths := include
include_paths := $(include_paths:%=-I%)

# empty := 
# library_path_export := $(subst $(empty) $(empty),:,$(library_paths))

cpp_compile_flags := -std=c++11 -w -g -O0 -fPIC -fopenmp -pthread
cpp_compile_flags += $(include_paths)

link_flags := -std=c++11 -Wall -O2 -g

#头文件修改后策略
ifneq ($(MAKECMDGOALS), clean)
-include $(cpp_mks) $(cu_mks)
endif

# .mk生成
# @g++ -MM $< -MF $@ -MT $(@:.mk=.o)
# 编译cpp依赖项，生成mk文件
objs/%.cpp.mk : src/%.cpp
	@echo Compile depends CXX $<
	@mkdir -p $(dir $@)
	@g++ -M $< -MF $@ -MT $(@:.cpp.mk=.cpp.o) $(cpp_compile_flags)

#编译CXX
objs/%.cpp.o : src/%.cpp
	@echo Compile CXX $<
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(cpp_compile_flags)

#链接
workspace/pro : $(cpp_objs) $(cu_objs)
	@printf "\n$(RED_COLOR)开始链接至$@...$(NO_COLOR)\n"
	@mkdir -p $(dir $@)
	g++ $^ -o $@ $(link_flags)

pro : workspace/pro
#@echo 编译完成 生成可执行文件$@
	@printf "\n$(RED_COLOR)编译完成，生成可执行文件$<$(NO_COLOR)\n"

run : pro
	@printf "\n$(RED_COLOR)成功运行...$(NO_COLOR)\n"
	@cd workspace && ./pro

clean:
	rm -rf workspace/pro objs

debug : workspace/pro
	@printf "\n$(RED_COLOR)readelf...$(NO_COLOR)\n"
	@readelf -d $<
	@printf "\n$(RED_COLOR)ldd...$(NO_COLOR)\n"
	@ldd $<

again:
	@make clean && make run

.PHONY: pro run clean debug again

var:
	@echo $(library_path_export)

# # 导出依赖库路径，使得能够运行起来

# export LD_LIBRARY_PATH:=$(library_path_export)

