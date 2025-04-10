<?php

/**
 * @TODO Document this class.
 */
class CivicrmEntity extends Entity {

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    if (empty($entityType)) {
      throw new Exception('Cannot create an instance of Entity without a specified entity type.');
    }
    $this->entityType = $entityType;
    $this->setUp();
    // Set initial values.
    foreach ($values as $key => $value) {
      // this is a bit of a hack around the fact we are casting to this to construct it
      if (stristr($key, "\0")) {
        continue;
      }
      $this->$key = $value;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function id() {
    return isset($this->id) ? $this->id : NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function entityType() {
    return 'civicrm_entity';
  }

  /**
   * {@inheritdoc}
   */
  public function label() {
    return $this->title;
  }

  /**
   * {@inheritdoc}
   */
  public function uri() {
    return array(
      'path' => 'task/' . $this->id(),
    );
  }
}

