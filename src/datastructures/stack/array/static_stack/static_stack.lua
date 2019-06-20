project "static_stack"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/src/%{prj.name}/"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/lib/"
    targetname "sstack"

    includedirs {
        "%{wks.location}/src/and/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/include/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_array/include/",
    }

    libdirs {
        "%{wks.location}/build/%{cfg.buildcfg}/lib/bitvector/lib/",
        "%{wks.location}/build/%{cfg.buildcfg}/lib/static_array/lib/",
    }

    links {
        "bitvector",
        "static_array",
    }

    filter "configurations:debug"
        defines {
            "DEBUG"
        }

        symbols "On"

        buildoptions {
            "--std=c99",
            "-pedantic",
            "-Wall",
            "-Werror",
            "-g",
        }

    filter "configurations:release"
        defines {
            "NDEBUG"
        }

        optimize "On"

        buildoptions {
            "--std=c99",
            "-pedantic",
            "-Wall",
            "-Werror",
        }

    filter {}
        files {
            "*.c"
        }

postbuildcommands {
    "{MKDIR} %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include",
    "{COPY} -u sstack.h %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include" 
}