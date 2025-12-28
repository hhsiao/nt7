// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("林欣彤[2;37;0m[2;37;0m", ({"juggernaut"}));        
        set("gender", "女性");                
        set("long", "看起來非常的牛B 屁股很大[2;37;0m
它是鄧紫棋的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jugger");
        set("owner_name", "鄧紫棋");
        set_temp("owner", "jugger");
        set_temp("owner_name", "鄧紫棋");
        ::setup();
}
