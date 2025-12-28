// xuemai1.c 血脈丹

#include <ansi.h>
#include "medicine.h"

int is_xuemai_dan() { return 1;}
void create()
{
        set_name(HIR "四品血脈丹" NOR, ({"xuemai dan4", "dan"}));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", "這是一粒血脈丹，可激活體內血脈能力。\n");
                set("base_unit", "顆");

                set("base_value", 200000);
                set("base_weight", 80);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "drug4"   : 1,
                                    "blood"   : 1,
                                    "xuelian2": 1,
                                    "yulu"    : 1,
                                    "sheli4"  : 1,
                                    "renshen2": 1,
                                    "puti4"   : 1,
                                    "lingzhi2": 1,
                                    "dimai"   : 1 ]),
                        "neili" : 300,
                        "jing"  : 50,
                        "time"  : 5,
                        "min_level" : 600,
                        "medical" : 1000,
                        "liandan-shu" : 3000,
                ]));
        }
        set("level", 4);
        setup();
}

int do_effect(object me) 
{
        write("血脈丹只能在修煉血脈upblood時候服用。\n"); 
        return 1;
}
