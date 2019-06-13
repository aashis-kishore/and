workspace "algorithms_n_datastructures"
    configurations { "debug", "release" }


-- src projects
dofile("./src/datastructures/stack/array/static_stack/static_stack.lua")
dofile("./src/datastructures/array/dynamic_array/dynamic_array.lua")                  -- dynamic_array
dofile("./src/datastructures/bitvector/bitvector.lua")                                  -- bitvector

-- src projects tests
dofile("./tests/test_static_stack/test_static_stack.lua")                               -- test_static_stack
dofile("./tests/test_dynamic_array/test_dynamic_array.lua")                             -- test_dynamic_array


newaction {
    trigger = "clean",
    description = "remove all generated directories from the root directory",
    execute = function()
        os.rmdir("./obj")
        os.rmdir("./build")
    end,
}