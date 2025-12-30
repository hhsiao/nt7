// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m遺忘[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "男性");                
        set("long", "一縷輕風，一壺清茶，伴隨著同樣又一個思念她的日和夜[2;37;0m
它是過去的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cod");
        set("owner_name", "過去");
        set_temp("owner", "cod");
        set_temp("owner_name", "過去");
        ::setup();
}
