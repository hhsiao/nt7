// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m靚[31m爆[1;33m你[1;34m雙眼[2;37;0m[2;37;0m[2;37;0m", ({"allure"}));        
        set("gender", "女性");                
        set("long", "靚爆你雙眼！[2;37;0m
它是小妞賊靚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "alluring");
        set("owner_name", "小妞賊靚");
        set_temp("owner", "alluring");
        set_temp("owner_name", "小妞賊靚");
        ::setup();
}
