// mbook.c
// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(HIY "煉丹筆記" NOR, ({ "liandan biji", "biji" }));
        set_weight(500);
                set("unit", "本");
                set("long", "這是一本謄寫的小本，上面用小篆書寫著“煉丹筆記”幾個字。\n");
                set("material", "paper");
                set("dynamic_quest", 1);
                set("no_sell", "這樣東西不能離開你。\n");
                set("no_put", "這樣東西不能放在那兒。\n");
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_get", "這樣東西不能離開那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                set("base_value", 0);
                set("skill", ([
                        "name": "liandan-shu",
                        "jing_cost": 80,
                        "difficulty": 40,
                        "max_skill": 150,
                        "min_skill": 30,
                ]));

                set("can_make", ([
                        "shujing"  : 50,        // 舒筋活絡丹
                        "dieda"    : 50,        // 跌打傷愈膏
                        "jiedu"    : 100,       // 牛黃解毒丸
                        "yuzhen"   : 250,       // 玉真散
                        "yuling"   : 250,       // 玉靈散
                        "yuqing"   : 300,       // 玉清散
                ]));
        setup();
}
