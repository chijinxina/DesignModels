###################单例模式################################
add_executable(Singleton_eh 单例模式/饿汉模式/Singleton_eh.cpp)
target_link_libraries(Singleton_eh pthread)
add_executable(Singleton_lh 单例模式/懒汉模式/Singleton_lh.cpp)
target_link_libraries(Singleton_lh pthread)
add_executable(Singleton_C++11 单例模式/C++11/Singleton_C++11.cpp)
target_link_libraries(Singleton_C++11 pthread)


###################抽象工厂模式################################
add_executable(AbstractFactory 抽象工厂模式/AbstractFactory.cpp)

######################工厂模式################################
add_executable(Factory 工厂模式/Factory.cpp)

######################迭代器模式################################
add_executable(Iterator 迭代器模式/Iterator.cpp)

######################外观模式################################
add_executable(Facade 外观模式Facade/Facade.cpp)

######################观察者模式################################
add_executable(Observer 观察者模式/Observer.cpp)