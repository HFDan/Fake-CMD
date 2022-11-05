project('fake-cmd', 'cpp', default_options:['c_std=c11', 'cpp_std=c++20'], version: '2.1.0rc1')


# Build dependent defines
if get_option('CD_32BIT')
	add_global_arguments('-m32"', language : 'c')
	add_global_arguments('-m32', language : 'cpp')
endif

if get_option('LUA_SUPPORT')
	add_global_arguments('-DLUASUPPORT', language : 'c')
	add_global_arguments('-DLUASUPPORT', language : 'cpp')
endif

if get_option('COMPILETIME_MODULE_SUPPORT')
	add_global_arguments('-DCOMPILETIMEMODULES', language : 'c')
	add_global_arguments('-DCOMPILETIMEMODULES', language : 'cpp')
endif

if host_machine.system() == 'windows'
	add_global_arguments('-DCLEAR_COMMAND="cls"', language : 'c')
	add_global_arguments('-DCLEAR_COMMAND="cls"', language : 'cpp')
endif

if host_machine.system() == 'linux'
	add_global_arguments('-DCLEAR_COMMAND="clear"', language : 'c')
	add_global_arguments('-DCLEAR_COMMAND="clear"', language : 'cpp')
endif

if not get_option('buildtype').startswith('debug')
	add_project_arguments('-DNDEBUG', language : 'cpp')
	add_project_arguments('-DNDEBUG', language : 'c')
endif

thread_dep = dependency('threads')

if get_option('COMPILETIME_MODULE_SUPPORT')
    libmodules_deps = [thread_dep]
    src_libmodules = ['src/modules/modules.cpp', 'src/modules/netstat.cpp', 'src/modules/syskey.cpp', 'src/modules/tree.cpp', 'src/modules/help.cpp', 'src/utility/utility.cpp']

    libmodules = static_library('libmodules', src_libmodules, dependencies: libmodules_deps, include_directories: include_directories('src/'))
endif

if get_option('LUA_SUPPORT')
    libruntimemodules_deps = [thread_dep]
    if get_option('STATIC_LUA')
        lua = subproject('lua')
        libruntimemodules_deps += [dependency('lua-5.4')]
    else
        libruntimemodules_deps += [dependency('lua', method: 'pkg-config')]
    endif
    src_libruntimemodules = ['src/lua/extensions/lua_fakecmd.cpp', 'src/modules/runtime_modules.cpp', 'src/lua/luaglobals.cpp'] 
    libruntimemodules = static_library('libruntimemodules', src_libruntimemodules, dependencies: libruntimemodules_deps, include_directories: include_directories('src/'))
endif

src_main = ['src/main.cpp', 'src/utility/utility.cpp']
if get_option('CD') == true
	if get_option('CD_32BIT') == true
		main_name = 'fake-cmd_i686'
	else
		main_name = 'fake-cmd_x86_64'
	endif
else
	main_name = 'fake-cmd_' + host_machine.cpu_family()
endif

libs_to_link_with = []
if get_option('LUA_SUPPORT')
    libs_to_link_with += [libruntimemodules]
endif
if get_option('COMPILETIME_MODULE_SUPPORT')
    libs_to_link_with += [libmodules]
endif

fakecmd = executable(main_name, src_main, dependencies: [thread_dep], include_directories: include_directories('src/'), link_with: [libs_to_link_with])
libfakecmd = static_library('libfakecmd', src_main, dependencies: [thread_dep], include_directories: include_directories('src/'), link_with: [libs_to_link_with])

if get_option('buildtype').startswith('debug')
    gtest = subproject('gtest')
    src_monolithictest = ['test/monolithicTest.cpp']
    monolithic_test = executable('monolithictest', src_monolithictest, dependencies: [dependency('gtest_main')], link_with: [libs_to_link_with], include_directories: include_directories('src/modules'))
    test('monolithic test', monolithic_test)
endif
