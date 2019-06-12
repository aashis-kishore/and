project "static_stack"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/src/%{prj.name}/"
    targetdir "%{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/lib/"
    targetname "sstack"

    includedirs {
        "%{wks.location}/dev_dependencies/print_messages/include",
        "%{wks.location}/src/and/"
    }

    filter "configurations:debug"
        defines {
            "DEBUG"
        }

        symbols "On"

        libdirs {
            "%{wks.location}/dev_dependencies/print_messages/lib"
        }

        links {
            "print_messages"
        }

    filter "configurations:release"
        defines {
            "NDEBUG"
        }

        optimize "On"

    filter {}
        files {
            "*.c"
        }

        buildoptions {
            "--std=c99",
            "-pedantic",
            "-Wall",
            "-Werror",
            -- "-fsanitize=address"
        }

postbuildcommands {
    "{MKDIR} %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include",
    "{COPY} -u sstack.h %{wks.location}/build/%{cfg.buildcfg}/lib/%{prj.name}/include" 
}