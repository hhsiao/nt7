// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[41;1m[1;36m天嵐紅塵[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "天嵐紅塵[2;37;0m
它是小聖的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dzd");
        set("owner_name", "小聖");
        set_temp("owner", "dzd");
        set_temp("owner_name", "小聖");
        ::setup();
}
