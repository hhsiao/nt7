// 五行陣
inherit SKI_ZHEN;

void create() {
    ::create();
    //set_menpai("溫家");                // 陣法所屬門派
    set_member_num(5);  // 陣形人數
    set_array_name("五行陣");  // 陣法名稱
    set_master_level(100);  // 陣主要求此陣法的最低等級
    set_member_level(50);   // 陣法成員要求此陣法的最低等級
    set_skill_type("wenjia-daofa");     // 陣法所使用的武功
    set_master_skill_level(100);    // 陣主武功等級
    set_member_skill_level(50);     // 成員武功等級
    set_effective_level(20);    // 陣法有效值
}
