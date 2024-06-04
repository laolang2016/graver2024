/**
 * @file person.h
 * @author your name (you@domain.com)
 * @brief 一个测试类
 * @version 0.1
 * @date 2024-01-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <string>

/**
 * @brief 一个测试类
 */
class Person {
public:
    /**
   * @brief Construct a new Person object
   */
    Person() = default;
    /**
   * @brief Construct a new Person object
   *
   * @param age 年龄
   * @param name 姓名
   */
    Person(int age, std::string &&name);
    ~Person() = default;

    /**
   * @brief 一个简单测试方法
   *
   * @return hello world
   */
    std::string sayHello();

    inline void age(int age) {
        this->m_age = age;
    }
    [[nodiscard]] inline int age() const {
        return this->m_age;
    }

    inline void name(std::string &&name) {
        this->m_name = std::move(name);
    }
    [[nodiscard]] inline std::string name() const {
        return this->m_name;
    }

private:
    /**
   * @brief  年龄
   */
    int m_age{0};
    /**
   * @brief 姓名
   */
    std::string m_name;
};
