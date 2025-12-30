// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大吉吉[2;37;0m[2;37;0m", ({"bigjb"}));        
        set("gender", "男性");                
        set("long", "一個用來。。。。。。的怪獸[2;37;0m
它是金瓶兒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jinpinger");
        set("owner_name", "金瓶兒");
        set_temp("owner", "jinpinger");
        set_temp("owner_name", "金瓶兒");
        ::setup();
}
