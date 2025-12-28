// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m踏雪[1;35m櫻花駒[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹神駒通體如雪，背上點點櫻花，貌似潘安、性如西門。[2;37;0m
它是西門慶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xmen");
        set("owner_name", "西門慶");
        set_temp("owner", "xmen");
        set_temp("owner_name", "西門慶");
        ::setup();
}
