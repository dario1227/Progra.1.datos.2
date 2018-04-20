//
// Created by kenneth on 19/04/18.
//

#include "Counter_resolving.h"
int Counter_resolving::scope_level = 0;
bool Counter_resolving::contains_alpha_dot(QString string) {
    if(string.contains(".")&&contains_solo_alpha(string)){
        return true;
    }
    else{
        return false;
    }

    }
bool Counter_resolving::contains_solo_alpha(QString string) {
    if(!string.contains("'")&&!string.contains(".")&&(string.contains('a',Qt::CaseInsensitive)||string.contains('q',Qt::CaseInsensitive)||string.contains('w',Qt::CaseInsensitive)||
        string.contains('e',Qt::CaseInsensitive)||string.contains('r',Qt::CaseInsensitive)||string.contains('t',Qt::CaseInsensitive)||
        string.contains('i',Qt::CaseInsensitive)||string.contains('u',Qt::CaseInsensitive)||string.contains('y',Qt::CaseInsensitive)||
        string.contains('o',Qt::CaseInsensitive)||string.contains('p',Qt::CaseInsensitive)||string.contains('s',Qt::CaseInsensitive)||
        string.contains('g',Qt::CaseInsensitive)||string.contains('f',Qt::CaseInsensitive)||string.contains('d',Qt::CaseInsensitive)||
        string.contains('h',Qt::CaseInsensitive)||string.contains('j',Qt::CaseInsensitive)||string.contains('k',Qt::CaseInsensitive)||
        string.contains('n',Qt::CaseInsensitive)||string.contains('m',Qt::CaseInsensitive)||string.contains('l',Qt::CaseInsensitive)||
        string.contains('b',Qt::CaseInsensitive)||string.contains('v',Qt::CaseInsensitive)||string.contains('c',Qt::CaseInsensitive)||
        string.contains('x',Qt::CaseInsensitive)||string.contains('z',Qt::CaseInsensitive))){
        return true;

    }
    else{
        return false;
    }}