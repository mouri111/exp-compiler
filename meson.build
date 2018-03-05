project('exp-compiler','c')

srcs = ['src/memory.c',
        'src/list.c',
        'src/string_builder.c',
       ]

incdir = include_directories('include', 'src')

warning_flags = ['-Wall',
                 '-Wextra',
                 '-Wshadow',
                 '-Werror',
                ]

opt_flags = ['-O2',
            ]

test_flags = ['-g3',
              '-fsanitize=address',
             ]

exe = executable('exp-compiler',
                 'app/exp-compiler.c',
                 srcs,
                 include_directories: incdir,
                 c_args: warning_flags + opt_flags
                )

test_memory = executable('test_memory',
                         'test/test_memory.c',
                         srcs,
                         include_directories: incdir,
                         c_args: warning_flags + test_flags + ['-coverage'],
                         link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                        )

test_assertion = executable('test_assertion',
                            'test/test_assertion.c',
                            srcs,
                            include_directories: incdir,
                            c_args: warning_flags + test_flags + ['-coverage'],
                            link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                           )

test_list = executable('test_list',
                       'test/test_list.c',
                       srcs,
                       include_directories: incdir,
                       c_args: warning_flags + test_flags + ['-coverage'],
                       link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                      )

test_string_builder = executable('test_string_builder',
                                 'test/test_string_builder.c',
                                 srcs,
                                 include_directories: incdir,
                                 c_args: warning_flags + test_flags + ['-coverage'],
                                 link_args: test_flags + ['-fuse-ld=gold'] + ['-coverage']
                                )

test('test_memory char_one failure',
     test_memory,
     args: ['char_one', 'failure'],
     should_fail: true
    )
test('test_memory char_one',
     test_memory,
     args: ['char_one'],
    )
test('test_memory char_many failure',
     test_memory,
     args: ['char_many', 'failure'],
     should_fail: true
    )
test('test_memory char_many',
     test_memory,
     args: ['char_many'],
    )
test('test_memory int_one failure',
     test_memory,
     args: ['int_one', 'failure'],
     should_fail: true
    )
test('test_memory int_one',
     test_memory,
     args: ['int_one'],
    )
test('test_memory int_many failure',
     test_memory,
     args: ['int_many', 'failure'],
     should_fail: true
    )
test('test_memory int_many',
     test_memory,
     args: ['int_many'],
    )
test('test_memory no argument',
     test_memory,
     should_fail: true
    )
test('test_memory nil test',
     test_memory,
     args: ['nil'],
     should_fail: true
    )
test('test_memory memalloc',
     test_memory,
     args: ['memalloc'],
    )
test('test_memory memalloc failure',
     test_memory,
     args: ['memalloc', 'failure'],
     should_fail: true
    )

test('test_assertion',
     test_assertion
    )
test('test_assertion failure',
     test_assertion,
     args: ['failure'],
     should_fail: true
    )

test('test_list no argument',
     test_list,
     should_fail: true
    )
test('test_list nil test',
     test_list,
     args: ['nil'],
     should_fail: true
    )
test('test_list size',
     test_list,
     args: ['size'],
    )
test('test_list push_back failure',
     test_list,
     args: ['push_back', 'failure'],
     should_fail: true
    )
test('test_list push_back',
     test_list,
     args: ['push_back'],
    )
test('test_list push_front failure',
     test_list,
     args: ['push_front', 'failure'],
     should_fail: true
    )
test('test_list push_front',
     test_list,
     args: ['push_front'],
    )
test('test_list pop_back',
     test_list,
     args: ['pop_back']
    )

test('test_string_builder nil',
     test_string_builder,
     should_fail: true,
    )
test('test_string_builder create_delete',
     test_string_builder,
     args: ['create_delete'],
    )
test('test_string_builder generate_cstring_1',
     test_string_builder,
     args: ['generate_cstring_1'],
    )
