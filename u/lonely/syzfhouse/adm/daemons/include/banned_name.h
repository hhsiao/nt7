//禁止使用的中文名字
string *banned_name =
({
"你", "你們", "我", "我們", "他", "他們", "她", "她們", "它", "它們",
"大家", "所有的人", "無", "某人",
"創始人", "系統", "核心", "系統核心", "系統管理員", "網管", "管理員",
"毛澤東", "周恩來", "鄧小平", "江澤民", "胡錦濤",
"精靈", "頻道精靈", "謠言精靈", "戰鬥精靈",
"天神", "大巫師", "巫師", "巫師學徒",
"女巫", "女巫師", "女天神", "女巫學徒",
"叮噹", "布丁", "行客兒", "阿蘭", "阿飛",
});

//禁止註冊的ID
string *banned_id =
({
"chat", "new", "rumor", "tell", "none", "reply",
"shutdown", "master", "core", "sys", "reboot",
"admin", "wizard", "arch",
"dick", "shit", "cao", "cunt", "slut", "damn",
"tnnd", "fuck", "fuckyou",
"dugu", "bubai", "all", "yuan", "chen", "chuanfu",
"east","west","south","north","enter","out",
"southeast","southwest","northeast","northwest",
"eastup", "eastdown", "westup", "westdown",
"southup", "southdown", "northup", "northdown", "corpse",
});

//被purge後仍在申訴期內的id
string *purge_id =
({
});

//開放多個登錄id的ip
string *bar_ip =
({
"202.98.13.2",//吉林一大學校園網
"61.132.182.2",//一學校代理
"218.104.54.7"//點擊網吧
});
