//
// Created by ASUSTek on 2017-03-27.
//

#include "SimpleTemplateEngine.h"
using std::cout;
int main()
{
    nets::View view{"{{template_with_underscore}}<=>{{template_with_underscore_missing}}"};
    cout << view.Render({{"template_with_underscore", "replacement"}});
    return 0;
}