project "print_messages"
    kind "StaticLib"
    language "C"
    objdir "%{wks.location}/obj/dev_support/%{prj.name}"
    targetdir "%{wks.location}/dev_dependencies/%{prj.name}/lib/"
    targetname "prntmsgs"

    files {
        "*.c"
    }

postbuildcommands {
    "{MKDIR} %{wks.location}/dev_dependencies/%{prj.name}/include/",
    "{COPY} -u prntmsgs.h %{wks.location}/dev_dependencies/%{prj.name}/include/prntmsgs.h"
}