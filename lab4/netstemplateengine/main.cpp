//
// Created by ASUSTek on 2017-03-27.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <map>
int main()
{
    nets::View view{"{{template_with_underscore}}<=>{{template_with_underscore_missing}}"};
    std::cout << view.Render({{"template_with_underscore", "replacement"}});
    return 0;
}