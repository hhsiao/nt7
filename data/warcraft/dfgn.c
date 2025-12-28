// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m令狐小衝[2;37;0m[2;37;0m", ({"white"}));        
        set("gender", "女性");                
        set("long", "一隻白老虎[2;37;0m
它是東方姑娘的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "dfgn");
        set("owner_name", "東方姑娘");
        set_temp("owner", "dfgn");
        set_temp("owner_name", "東方姑娘");
        ::setup();
}
