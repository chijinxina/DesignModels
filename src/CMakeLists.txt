add_executable(Singleton_eh 单例模式/饿汉模式/Singleton_eh.cpp)
target_link_libraries(Singleton_eh pthread)
add_executable(Singleton_lh 单例模式/懒汉模式/Singleton_lh.cpp)
target_link_libraries(Singleton_lh pthread)
