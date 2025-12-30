// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m腳踏地[2;37;0m[2;37;0m", ({"yanga"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是楊頂天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yang");
        set("owner_name", "楊頂天");
        set_temp("owner", "yang");
        set_temp("owner_name", "楊頂天");
        ::setup();
}
