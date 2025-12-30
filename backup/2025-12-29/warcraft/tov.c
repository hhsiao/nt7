// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m麒[1;32m麟[1;31m神[1;37m王[2;37;0m[2;37;0m", ({"asa"}));        
        set("gender", "女性");                
        set("long", "這是麒麟一族的王者，其族人見到它都會不由自主的膜拜。[2;37;0m
它是手殘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tov");
        set("owner_name", "手殘");
        set_temp("owner", "tov");
        set_temp("owner_name", "手殘");
        ::setup();
}
