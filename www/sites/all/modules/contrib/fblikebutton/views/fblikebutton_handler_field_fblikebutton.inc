<?php

class fblikebutton_handler_field_fblikebutton extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $output = NULL;
    $nid = $values->nid;
    $types = variable_get('fblikebutton_node_types', array());
    $show = (!empty($types[$values->node_type]) && user_access('access fblikebutton'));
    
    $conf = array(
      'layout' => variable_get('fblikebutton_layout', 'standard'),
      'action' => variable_get('fblikebutton_action', 'like'),
      'color_scheme' => variable_get('fblikebutton_color_scheme', 'light'),
      'show_faces' => variable_get('fblikebutton_show_faces', 'true'),
      'font' => variable_get('fblikebutton_font', 'arial'),
      'height' => variable_get('fblikebutton_iframe_height', '80'),
      'width' => variable_get('fblikebutton_iframe_width', '450'),
      'send' => variable_get('fblikebutton_send', 'true'),
      'other_css' => variable_get('fblikebutton_iframe_css', ''),
      'language' => variable_get('fblikebutton_language', 'en_US'),
    );
    $webpage_to_like = url("node/$nid", array('absolute' => TRUE));
    
    if ($show) {
      $output = _fblikebutton_field($webpage_to_like, $conf);
    }
    
    return $output;
  }
}