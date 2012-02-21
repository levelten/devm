api = 2
core = "7.12"

;;;;;;
; Fields
;;;;;;
projects[date][version] = 2.0-rc2
projects[field_group][version] = 1.1
projects[link][version] = 1.0
projects[options_element][version] = 1.5
projects[references][version] = 2.0
projects[filefield_sources][version] = 1.4

;;;;;;
; Path Tools
;;;;;;
projects[globalredirect][version] = 1.4
projects[pathauto][version] = 1.0
projects[redirect][version] = 1.0-beta4
projects[transliteration][version] = 3.0


;;;;;;
; Sitebuilding tools
;;;;;;
projects[apps][version] = 1.0-beta5
; Fix error during install.
; http://drupal.org/node/1417916
projects[apps][patch][1417916] = http://drupal.org/files/apps_install_profile_foreach_error.1417916.patch
; Fix continue when apps server is unavailable.
; http://drupal.org/node/1422086
projects[apps][patch][1422086] = http://drupal.org/files/apps_profile_no_internet.1422086.patch
; Fix continue when apps server is unavailable.
; http://drupal.org/node/1422254
projects[apps][patch][1422254] = http://drupal.org/files/apps_profile_download_fail.1422254.patch
; Fix Installation Profile additions formatting.
; http://drupal.org/node/1431992
projects[apps][patch][1431992] = http://drupal.org/files/1431992-update-install-profile-def.patch
projects[backup_migrate][version] = 2.2
projects[boxes][version] = 1.0-beta7
projects[ctools][version] = 1.0-rc1
projects[defaultcontent][version] = 1.0-alpha4
projects[email_registration][version] = 1.0
projects[entity][version] = 1.0-rc1
projects[entitycache][version] = 1.1
projects[features][version] = 1.0-beta6
; Fix user_permissions so only for included roles.
; http://drupal.org/node/656312
projects[features][patch][656312] = http://drupal.org/files/issues/features_permission_export-656312-11--D7.patch
projects[features_override][version] = 1.0-beta1
projects[libraries][version] = 1.0
projects[menu_block][version] = 2.3
projects[strongarm][version] = 2.0-beta5
projects[token][version] = 1.0-rc1
projects[views][version] = 3.1

;;;;;;
; Text Editor
;;;;;;
projects[imce][version] = 1.5
projects[imce_wysiwyg][version] = 1.0
;; No D7 release yet
;projects[better_formats][version] = 1.x-dev
projects[insert][version] = 1.1
projects[caption_filter][version] = 1.2
projects[image_resize_filter][version] = 1.13
projects[wysiwyg][version] = 2.1
; Fix path_to_theme()
; http://drupal.org/node/835682
projects[wysiwyg][patch][835682] = http://drupal.org/files/issues/wysiwyg-835682-12.patch
; Fix empty font styles drop down()
; http://drupal.org/node/746524
projects[wysiwyg][patch][746524] = http://drupal.org/files/746524-143-D7.patch
projects[wysiwyg_filter][version] = 1.6-rc2

;;;;;;
; UI Enhancements
;;;;;;
projects[backports][version] = 1.0-alpha1
projects[block_visibility][version] = 1.0-beta2
projects[nodeconnect][version] = 1.0-alpha1
projects[simplified_menu_admin][version] = 1.0-beta2
projects[elements][version] = 1.2
projects[admin_menu][version] = 3.0-rc1

;;;;;
; Libraries
;;;;;

libraries[tinymce][download][version] = "get"
libraries[tinymce][download][url] = "http://cloud.github.com/downloads/tinymce/tinymce/tinymce_3.4.8.zip"
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][destination] = "libraries"

;;;;;;
; Theme
;;;;;;

projects[tao][version] = 3.0-beta4
projects[rubik][version] = 4.0-beta7
projects[omega][version] = 3.0

