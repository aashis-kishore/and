workspace "algorithms_n_datastructures"
    configurations { "debug", "release" }


-- dev_util projects
dofile("./src/and/viewmemutils/viewmemutils.lua")                                       -- viewmemutils

-- dev_util project tests
dofile("./tests/test_viewmemutils/test_viewmemutils.lua")                               -- test_viewmemutils


-- src projects
dofile("./src/datastructures/stack/array/static_stack/static_stack.lua")
dofile("./src/datastructures/array/dynamic_array/dynamic_array.lua")                  -- dynamic_array
dofile("./src/datastructures/bitvector/bitvector.lua")                                  -- bitvector
dofile("./src/datastructures/array/static_array/static_array.lua")                      -- static_array
dofile("./src/algorithms/other/fibonacci/fibonacci.lua")                                -- fibonacci

-- src projects tests
dofile("./tests/test_static_stack/test_static_stack.lua")                               -- test_static_stack
dofile("./tests/test_dynamic_array/test_dynamic_array.lua")                             -- test_dynamic_array
dofile("./tests/test_bitvector/test_bitvector.lua")                                      -- test_bitvector
dofile("./tests/test_static_array/test_static_array.lua")                               -- test_static_array
dofile("./tests/test_fibonacci/test_fibonacci.lua")                                     -- test_fibonacci


newaction {
    trigger = "clean",
    description = "remove all generated directories from the root directory",
    execute = function()
        os.rmdir("./obj")
        os.rmdir("./build")
    end,
}