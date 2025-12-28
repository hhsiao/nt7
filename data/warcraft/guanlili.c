// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("布萊恩[2;37;0m[2;37;0m", ({"bryan"}));        
        set("gender", "女性");                
        set("long", "可愛的布萊恩！[2;37;0m
它是可妮的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "guanlili");
        set("owner_name", "可妮");
        set_temp("owner", "guanlili");
        set_temp("owner_name", "可妮");
        ::setup();
}
