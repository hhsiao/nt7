// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m曉曉胯下物[2;37;0m[2;37;0m", ({"suxx"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是蘇曉曉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "suxiaoxiao");
        set("owner_name", "蘇曉曉");
        set_temp("owner", "suxiaoxiao");
        set_temp("owner_name", "蘇曉曉");
        ::setup();
}
