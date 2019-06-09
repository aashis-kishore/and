workspace "datum_algum"
    configurations { "debug", "release" }

-- dev_support projects
dofile("./dev_support/print_messages/print_messages.lua")

-- dev_support projects tests
dofile("./tests/dev_support/test_print_messages/test_print_messages.lua")


newaction {
    trigger = "clean",
    description = "remove all generated directories from the root directory",
    execute = function()
        os.rmdir("./obj")
        os.rmdir("./build")
    end,
}