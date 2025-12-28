// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小鳥[2;37;0m[2;37;0m", ({"lisa"}));        
        set("gender", "女性");                
        set("long", "小鳥[2;37;0m
它是鬼腳妮的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "morgan");
        set("owner_name", "鬼腳妮");
        set_temp("owner", "morgan");
        set_temp("owner_name", "鬼腳妮");
        ::setup();
}
