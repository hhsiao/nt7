// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("泡泡龍[2;37;0m[2;37;0m", ({"goto"}));        
        set("gender", "女性");                
        set("long", "泡泡...[2;37;0m
它是滅莉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "loli");
        set("owner_name", "滅莉");
        set_temp("owner", "loli");
        set_temp("owner_name", "滅莉");
        ::setup();
}
