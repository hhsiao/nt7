// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"alias_m_whistle_zixc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是赫連悶悶的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bagbage");
        set("owner_name", "赫連悶悶");
        set_temp("owner", "bagbage");
        set_temp("owner_name", "赫連悶悶");
        ::setup();
}
