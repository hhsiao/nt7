// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小青蛇[2;37;0m[2;37;0m", ({"qingshe"}));        
        set("gender", "男性");                
        set("long", "一條還未化龍的小青蛇,頭上已經開始要長角了。[2;37;0m
它是康米的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nickhelp");
        set("owner_name", "康米");
        set_temp("owner", "nickhelp");
        set_temp("owner_name", "康米");
        ::setup();
}
