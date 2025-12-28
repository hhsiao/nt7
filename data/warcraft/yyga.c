// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雞雞[2;37;0m[2;37;0m", ({"xjj"}));        
        set("gender", "男性");                
        set("long", "不解釋[2;37;0m
它是押運一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yyga");
        set("owner_name", "押運一");
        set_temp("owner", "yyga");
        set_temp("owner_name", "押運一");
        ::setup();
}
