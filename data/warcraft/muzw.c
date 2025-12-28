// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白狐[2;37;0m[2;37;0m", ({"huzi"}));        
        set("gender", "女性");                
        set("long", "白[2;37;0m
它是鳳飛翔的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "muzw");
        set("owner_name", "鳳飛翔");
        set_temp("owner", "muzw");
        set_temp("owner_name", "鳳飛翔");
        ::setup();
}
