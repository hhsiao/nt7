// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"kissbye"}));        
        set("gender", "女性");                
        set("long", "締結永生的血之盟約。[2;37;0m
它是玄虛的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hioo");
        set("owner_name", "玄虛");
        set_temp("owner", "hioo");
        set_temp("owner_name", "玄虛");
        ::setup();
}
