// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m豔豔[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "女性");                
        set("long", "這鳥非常好看[2;37;0m
它是長孫無垢的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ashley");
        set("owner_name", "長孫無垢");
        set_temp("owner", "ashley");
        set_temp("owner_name", "長孫無垢");
        ::setup();
}
