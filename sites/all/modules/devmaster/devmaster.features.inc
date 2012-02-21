<?php
/**
 * @file
 * devmaster.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function devmaster_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function devmaster_node_info() {
  $items = array(
    'devmaster_client' => array(
      'name' => t('Client'),
      'base' => 'node_content',
      'description' => t('A development client which will have site instances'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'devmaster_site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A site instance i.e. dev, test'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
