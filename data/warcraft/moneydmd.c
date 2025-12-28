// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"alias_m_whistle_zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是黃絹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneydmd");
        set("owner_name", "黃絹");
        set_temp("owner", "moneydmd");
        set_temp("owner_name", "黃絹");
        ::setup();
}
