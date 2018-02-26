<?php

/**
 * Implements hook_views_data().
 */
function fblikebutton_views_data() {
  $data['node']['fblikebutton'] = array(
    'field' => array(
      'title' => t('Facebook Like Button'),
      'help' => t('Adds a facebook like button.'),
      'handler' => 'fblikebutton_handler_field_fblikebutton',
    ),
  );
  
  return $data;
}
