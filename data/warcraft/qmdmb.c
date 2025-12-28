// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"alias_m_whistle_zixc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是骨精靈的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qmdmb");
        set("owner_name", "骨精靈");
        set_temp("owner", "qmdmb");
        set_temp("owner_name", "骨精靈");
        ::setup();
}
