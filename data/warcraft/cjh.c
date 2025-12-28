// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("罹[1;31m天[1;31m火[1;31m[2;37;0m[2;37;0m", ({"huo"}));        
        set("gender", "男性");                
        set("long", "赤焰焚三界,傲世滅輪迴[2;37;0m
它是罹天無雙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cjh");
        set("owner_name", "罹天無雙");
        set_temp("owner", "cjh");
        set_temp("owner_name", "罹天無雙");
        ::setup();
}
