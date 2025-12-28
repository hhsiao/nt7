// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m趴趴熊[1;33m[2;37;0m[2;37;0m", ({"dustpp"}));        
        set("gender", "女性");                
        set("long", "這是一直奇異的玩偶小熊，它所到之處寸草不生。[2;37;0m
它是客官別怕的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dusty");
        set("owner_name", "客官別怕");
        set_temp("owner", "dusty");
        set_temp("owner_name", "客官別怕");
        ::setup();
}
