// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("油加栗[2;37;0m[2;37;0m", ({"youjia"}));        
        set("gender", "女性");                
        set("long", "綠油油的樹[2;37;0m
它是無尾熊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wuweixiong");
        set("owner_name", "無尾熊");
        set_temp("owner", "wuweixiong");
        set_temp("owner_name", "無尾熊");
        ::setup();
}
